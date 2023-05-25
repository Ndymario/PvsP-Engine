extends Node

class_name Collectable

@export var collected: bool = false
@export var animation_tree: AnimationTree

func collect():
	if animation_tree != null:
		animation_tree.get("parameters/playback").travel("collected")
	else:
		get_parent().queue_free()
		collected = true

func _on_animation_tree_animation_finished(anim_name):
	if anim_name == "collected":
		get_parent().queue_free()
		collected = true
