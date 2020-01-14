from objloader import *
import random

class Box:
	def __init__(self, initial_x, initial_z, z_max, z_spawn):
		# X positivo vai pra direita
		# Y positivo vai pra cima
		# Z positivo vai para tras
		self.coords = [0, 0, initial_z]
		self.model = OBJ("./nova2_box.obj")
		self.scale_factor = (1.25,1,1)
		self.options = [-2-1,0,1,2]
		self.z_max = z_max
		self.z_spawn = z_spawn
		self.size = 0.8

	def render(self):
		glPushMatrix()
		glScale(self.scale_factor[0], self.scale_factor[1], self.scale_factor[2])
		glTranslatef(self.coords[0], self.coords[1], self.coords[2])
		glCallList(self.model.gl_list)
		glPopMatrix()

	def update(self, SPEED_RATE):
		z_final = self.coords[2] + SPEED_RATE
		if z_final > self.z_max:
			z_final = self.z_spawn
			self.coords[0] = random.choice(self.options)
		self.coords[2] = z_final
