extends State

class_name WallSlideState

@export var ground_state: State
@export var jump_velocity: float = -250
@export var horizontal_jump_velocity: float = 100
@export var wall_slide_speed: float = ProjectSettings.get_setting("physics/2d/default_gravity")
@export var air_state: State
@export var wall_slide_animation: String = "climb"
@export var jump_animation: String = "jump"

var direction: int = 0

func on_enter():
	playback.travel("climb")
	can_move = false
	
	if character.sprite.flip_h:
		direction = 1
		
	else:
		direction = -1

func state_process(delta):
	if character.is_on_floor():
		next_state = ground_state
		
	elif not character.is_on_wall():
		next_state = air_state
		
	character.velocity.y = lerp(0.0, wall_slide_speed, 0.001)
		
func state_input(event: InputEvent):
	if event.is_action_pressed("jump") && not character.dummy:
		jump()
		
func jump():
	character.velocity.y = jump_velocity
	character.position.x = lerp(character.position.x, character.position.x + horizontal_jump_velocity * direction, 0.1)
	next_state = air_state
	playback.travel(jump_animation)
