from pygame.locals import *
from pygame.constants import *
from OpenGL.GL import *
from OpenGL.GLU import *
from OpenGL.GLUT import *
from Car import *
from Tree import *
from Box import *
from Road import *

class Scene:
	TRACK_HEIGHT = 50
	TRACK_LENGHT = 7
	GRASS_LENGHT = TRACK_LENGHT * 20

	def __init__(self):
		self.car = Car(self.TRACK_LENGHT)
		self.road = Road()
		self.ambient = self.init_ambient() #lista de objetos que nao colidem com o carro
		self.obstacles = self.init_obstacles()
		self.angle = 50
		self.game_over = False
	
	def init_ambient(self):
		ambient = []

		ambient.append(Tree(self.TRACK_LENGHT - 30, -20, 30, -20))
		ambient.append(Tree(self.TRACK_LENGHT - 30, -5, 30, -20))
		ambient.append(Tree(self.TRACK_LENGHT - 30, 15, 30, -20))
		ambient.append(Tree(self.TRACK_LENGHT + 15, -20, 30, -20))
		ambient.append(Tree(self.TRACK_LENGHT + 15, -5, 30, -20))
		ambient.append(Tree(self.TRACK_LENGHT + 15, 15, 30, -20))
		return ambient

	def init_obstacles(self):
		obstacles = []
		# obstacles.append(Box(self.TRACK_LENGHT, -30, 30, -60))
		obstacles.append(Box(self.TRACK_LENGHT, -30, 30, -30))
		return obstacles

	def render_ground(self):
		pass
		glColor3f(0.0, 0.8, 1.0)
		gluSphere(gluNewQuadric(),250,200,200)
		# RIGHT GRASS
				

		glBegin(GL_QUADS)
		glColor3f(0.0, 1.0, 0.0)
		glVertex3f(self.GRASS_LENGHT, -5, -self.TRACK_HEIGHT - 15)
		glVertex3f(-self.GRASS_LENGHT - 20, -5, -self.TRACK_HEIGHT - 15)
		glVertex3f(-self.GRASS_LENGHT -20, -5, self.TRACK_HEIGHT)
		glVertex3f(self.GRASS_LENGHT + 20, -5, self.TRACK_HEIGHT)
		glEnd()

		# TRACK
		# glBegin(GL_QUADS)
		# glColor3f(1.0, 1.0, 1.0)
		# glVertex3f(self.TRACK_LENGHT, 0, -self.TRACK_HEIGHT)
		# glVertex3f(-self.TRACK_LENGHT, 0, -self.TRACK_HEIGHT)
		# glVertex3f(-self.TRACK_LENGHT, 0, self.TRACK_HEIGHT)
		# glVertex3f(self.TRACK_LENGHT, 0, self.TRACK_HEIGHT)
		# glEnd()

	def render_scene(self):

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)
		glMatrixMode(GL_MODELVIEW)
		glLoadIdentity()

		gluLookAt(0, 5, 20, 0, 1.2, 0, 0, 1, 0) # PER
		# gluLookAt(0, 15, 5, 0, -90, 0, 0, 1, 0) # TOP

		self.car.render_car()
		self.road.render()
		self.render_obstacles()
		self.render_ground()
		self.render_ambient()

	def render_ambient(self):
		for obj in self.ambient:
			obj.render()


	def render_obstacles(self):
		for obj in self.obstacles:
			obj.render()

	def update(self,SPEED_RATE):
		self.road.update()
		for obj in self.ambient:
			obj.update(SPEED_RATE)
		for obj in self.obstacles:
			obj.update(SPEED_RATE)
			self.game_over = self.car.check_collision(obj)


		
