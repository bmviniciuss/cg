from objloader import *
import os, random,math

class Road:
	def __init__(self):
		# X positivo vai pra direita
		# Y positivo vai pra cima
		# Z positivo vai para tras
		# 195 ta fora
		# -200 span
		self.coords = [0.5, 0, 2.5]  # Car coordinates [X,Y,Z]
		self.model = OBJ("./rua3.obj")
		# self.scale_factor = (3, 0, 25)
		self.scale_factor = (3, 1, 25)
		self.size = 0.8
		self.i = 10

		# open("rua.jpg")


	def render(self):
		# print "CORDS CAIXA"+ str(self.coords)
		glPushMatrix()
		glMatrixMode(GL_MODELVIEW)
		glScale(self.scale_factor[0], self.scale_factor[1], self.scale_factor[2])
		glTranslatef(self.coords[0], self.coords[1], self.coords[2])
		glRotatef(90, 0,1,0)
		glCallList(self.model.gl_list)
		glPopMatrix()
	
	def update(self):
		# self.coords[2] += 0.001
		glMatrixMode(GL_TEXTURE)
		glTranslatef(math.cos(math.radians(-self.i)),0,0)
	