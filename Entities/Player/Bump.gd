extends State

class_name BumpState

@export var bump_velocity: float = 300
@export var bump_speed: float = 15
@export var ground_state: State
@export var air_state: State
@export var bump_animation: String = "dead"

var is_bumped: bool = true
var og_speed: int

func state_process(delta):
	print(character.speed)
	can_move = false
	
	if not is_bumped:
		bump()
		
	if character.velocity.x == 0 && character.velocity.y == 0:
		is_bumped = false
		character.speed = og_speed
		
		if character.is_on_floor():
			next_state = ground_state
		else:
			next_state = air_state
		
func bump():
	character.speed = bump_speed
	is_bumped = true
	var rand_direction = pow(-1, randi() % 2)
	character.velocity.x = bump_velocity * rand_direction
	character.velocity.y = bump_velocity
		
	playback.travel(bump_animation)
