extends Node

class_name Collectable

@export var collected: bool = false

func collect():
	get_parent().queue_free()
	collected = true
