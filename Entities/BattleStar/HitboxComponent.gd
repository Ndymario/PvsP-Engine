extends Area2D

class_name Hitbox

@export var collectable: Collectable

func collect():
	if collectable:
		collectable.collect()
