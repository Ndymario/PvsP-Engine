extends State

class_name BumpState

@export var bump_velocity: float = 500
@export var bump_speed: float = 100
@export var bump_inc_multiplier: float = 1
@export var ground_state: State
@export var air_state: State
@export var bump_animation: String = "dead"

var is_bumped: bool = true

func state_process(delta):
	can_move = false
	
	if not is_bumped:
		bump()
	
	character.speed = lerp(0.0, bump_speed, 0.05 * bump_inc_multiplier)
	
	bump_inc_multiplier += 0.8
		
	if character.velocity.x == 0 && character.velocity.y == 0:
		is_bumped = false
		bump_inc_multiplier = 1
		
		if character.is_on_floor():
			next_state = ground_state
		else:
			next_state = air_state
		
func bump():
	is_bumped = true
	var rand_direction = pow(-1, randi() % 2)
	character.velocity.x = bump_velocity * rand_direction
	character.velocity.y = bump_velocity
		
	playback.travel(bump_animation)
