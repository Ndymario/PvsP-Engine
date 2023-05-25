extends Node

class_name CharacterStateMachine

@export var current_state: State
@export var animation_tree: AnimationTree

var states: Array[State]

func _ready():
	for child in get_children():
		if child is State:
			states.append(child)
			
			# Set up states with needed data
			child.character = $".."
			child.playback = animation_tree["parameters/playback"]
			
		else:
			push_warning("Child " + child.name + " is not a State for CharacterStateMachine")

func _physics_process(delta):
	if current_state.next_state != null:
		switch_state(current_state.next_state)
		
	current_state.state_process(delta)

func can_move():
	return current_state.can_move

func switch_state(new_state: State):
	if current_state != null:
		current_state.on_exit()
		current_state.next_state = null
	
	current_state = new_state
	
	current_state.on_enter()
	
func _input(event: InputEvent):
	current_state.state_input(event)
