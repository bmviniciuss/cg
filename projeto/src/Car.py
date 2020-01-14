from objloader import *
import os

class Car:
	BASE_ROTATION = 180
	TRANSLATION_RATE = 0.5
	ROTATION_RATE = 8

	ROTATION_LEFT_LIMIT = BASE_ROTATION + ROTATION_RATE
	ROTATION_RIGHT_LIMIT = BASE_ROTATION - ROTATION_RATE

	def __init__(self, LENGHT):
		# X positivo vai pra direita
		# Y positivo vai pra cima
		# Z positivo vai para tras
		self.coords = [0, 1.5, 20]  # Car coordinates [X,Y,Z]
		self.model = OBJ("./Car.obj")
		self.scale_factor = 0.65
		self.rotate = 0
		self.LEFT_LIMIT = -LENGHT
		self.RIGHT_LIMIT = LENGHT

	def render_car(self):
		glPushMatrix()
		rotation_angle = self.rotate + self.BASE_ROTATION
		glScale(self.scale_factor, self.scale_factor, self.scale_factor)
		glTranslatef(self.coords[0], self.coords[1], self.coords[2])
		glRotatef(rotation_angle, 0, 1, 0)
		# glBegin(GL_QUADS)
		# glColor3f(1.0, 0, 0)
		# glVertex3f(2, 0, -5)
		# glVertex3f(-2, 0, -5)
		# glVertex3f(-2, 0, 5)
		# glVertex3f(2, 0, 5)
		# glEnd()
		glCallList(self.model.gl_list)
		glPopMatrix()

	def move_right(self):
		x_final = self.coords[0] + self.TRANSLATION_RATE
		if x_final <= self.RIGHT_LIMIT:
			self.coords[0] = x_final

	def rotate_right(self):
		amount = (self.rotate + self.BASE_ROTATION) - self.ROTATION_RATE
		if amount <= self.ROTATION_RIGHT_LIMIT:
			amount = self.ROTATION_RIGHT_LIMIT - self.BASE_ROTATION
		self.rotate = amount

	def move_left(self):
		x_final = self.coords[0] - self.TRANSLATION_RATE
		if x_final >= self.LEFT_LIMIT:
			self.coords[0] = x_final

	def rotate_left(self):
		amount = (self.rotate + self.BASE_ROTATION) + self.ROTATION_RATE
		if amount >= self.ROTATION_LEFT_LIMIT:
			amount = self.ROTATION_LEFT_LIMIT + self.BASE_ROTATION
		self.rotate = amount

	def move_forward(self):
		y_final = self.coords[2] - self.TRANSLATION_RATE
		self.coords[2] = y_final

	def move_backwards(self):
		y_final = self.coords[2] + self.TRANSLATION_RATE
		self.coords[2] = y_final

	def check_collision(self, obj):
		lenth = 5
		width = 2
		# (obj.coords[2] - obj.size )>= (self.coords[2] - lenth)
		x_car = self.coords[0]
		z_car = self.coords[2]
		x_box = obj.coords[0]
		z_box = obj.coords[2]
		# print "X_CARRO = " + str(x_car) + " Z_CAR = " + str(z_car)
		# print "X_BOX = " + str(x_box) + " Z_BOX = " + str(z_box)
		frente = z_car - lenth
		tras_caixa = z_box - obj.size
		# print "FRENTE " + str(frente)
		# print "TRAS CAIXA " + str(tras_caixa)
		check_z = z_box - 4 >= 8 and z_box < 17
		check_x = x_box - 4  < x_car + width - 2 and x_box + 2 > x_car - width
		# if check_z and check_x:
			# print 'DENTRO'
		# a = (obj.coords[2] + obj.size * 5.5 ) >= (self.coords[2] - lenth) and (obj.coords[2] + obj.size) <= (self.coords[2] + lenth)
		# b = (obj.coords[2]) <= (self.coords[2] + lenth)
		# print 
		return check_z and check_x