extends CharacterBody2D

class_name Player

@export var speed: float = 160.0
@export var air_penalty: float = 0.75
@export var dummy: bool = false
@export var dummy_color: String = "555555"

@onready var sprite: Sprite2D = $SmallMario
@onready var animation_tree: AnimationTree = $AnimationTree
@onready var state_machine: CharacterStateMachine = $CharacterStateMachine

# Get the gravity from the project settings to be synced with RigidBody nodes.
var gravity = ProjectSettings.get_setting("physics/2d/default_gravity")

var direction: Vector2 = Vector2.ZERO

func _ready():
	animation_tree.active = true
	if dummy:
		sprite.modulate = dummy_color

func _physics_process(delta):
	# Add the gravity.
	if not is_on_floor():
		velocity.y += gravity * delta
			
	# Get the input direction and handle the movement/deceleration.
	direction = Input.get_vector("left", "right", "up", "down")
	
	if dummy:
		direction = Vector2.ZERO
		
	if direction.x != 0 && state_machine.can_move():
		velocity.x = direction.x * speed
		
		if not is_on_floor():
			velocity.x = velocity.x * air_penalty

	else:
		velocity.x = move_toward(velocity.x, 0, speed)

	move_and_slide()
	update_animation_parameters()
	update_facing_direction()
	
func update_animation_parameters():
	animation_tree.set("parameters/Move/blend_position", direction.x)
			
func update_facing_direction():
	if direction.x > 0:
		sprite.flip_h = false
	elif direction.x < 0:
		sprite.flip_h = true

func _on_torso_hitbox_area_entered(area):
	if area is Hitbox:
		if !(area.get_parent() is Player):
			var hitbox: Hitbox = area
			
			area.collect()
		
		else:
			area.get_parent().velocity.x = 300 * Input.get_vector("left", "right", "up", "down").x

func _on_feet_hitbox_area_entered(area):
	if area is Hitbox:
		if !(area.get_parent() is Player && area.get_parent() != self):
			var hitbox: Hitbox = area
			
			area.collect()
		
		else:
			velocity.y = -250

func _on_head_hitbox_area_entered(area):
	if area is Hitbox:
		if !(area.get_parent() is Player && area.get_parent() != self):
			var hitbox: Hitbox = area
			
			area.collect()
		
		else:
			state_machine.current_state = $CharacterStateMachine/Bump
