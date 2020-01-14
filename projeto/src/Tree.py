from objloader import *
import os, random

class Tree:
	def __init__(self, initial_x, initial_z, z_max, z_spawn):
		# X positivo vai pra direita
		# Y positivo vai pra cima
		# Z positivo vai para tras
		self.coords = [initial_x, 5, initial_z]
		self.model = OBJ("./lowpoly_tree.obj")
		self.scale_factor = (0.35, 0.35, 0.65)
		self.z_max = z_max
		self.z_spawn = z_spawn

	def render(self):
		glPushMatrix()
		glMatrixMode(GL_MODELVIEW)
		glScale(self.scale_factor[0], self.scale_factor[1], self.scale_factor[2])
		glTranslatef(self.coords[0], self.coords[1], self.coords[2])
		glCallList(self.model.gl_list)
		glPopMatrix()
	

	def update(self, SPEED_RATE):
		z_final = self.coords[2] + SPEED_RATE
		if z_final > self.z_max:
			z_final = self.z_spawn
		self.coords[2] = z_final
