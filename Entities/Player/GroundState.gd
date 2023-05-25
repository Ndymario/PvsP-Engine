extends State

class_name GroundState

@export var jump_velocity: float = -250
@export var air_state: State
@export var jump_animation: String = "jump"

func on_enter():
	character.speed = 160.0
	character.air_penalty = 0.75
	playback.travel("Move")

func state_process(delta):
	if not character.is_on_floor():
		next_state = air_state

func state_input(event: InputEvent):
	if event.is_action_pressed("jump") && not character.dummy:
		jump()
		
func jump():
	character.velocity.y = jump_velocity
	next_state = air_state
	playback.travel(jump_animation)
