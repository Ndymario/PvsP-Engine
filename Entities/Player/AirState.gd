extends State

class_name AirState

@export var ground_state: GroundState
@export var wall_slide_state: WallSlideState
@export var double_jump_velocity: float = -300

var has_double_jumped = false

func on_enter():
	can_move = false
	playback.travel("jump")

func state_process(delta):
	if abs(character.velocity.x) < 250:
		can_move = true
		
	if character.is_on_floor():
		next_state = ground_state
		
	if character.is_on_wall():
		next_state = wall_slide_state
		
func state_input(event: InputEvent):
	if event.is_action_pressed("jump") && not has_double_jumped && not character.dummy:
		double_jump()
		
func on_exit():
	if next_state == ground_state:
		has_double_jumped = false

func double_jump():
	character.velocity.y = double_jump_velocity
	has_double_jumped = true
	playback.travel("double_jump")
