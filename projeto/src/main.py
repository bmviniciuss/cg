import sys
import pygame
import math
from pygame.locals import *
from pygame.constants import *
from OpenGL.GL import *
from OpenGL.GLU import *
from OpenGL.GLUT import *
from Scene import *

viewport = (640, 480)
hx = viewport[0]/2
hy = viewport[1]/2

def main():
    SPEED_RATE = 0.5
    pygame.init()
    display = pygame.display.set_mode(viewport, pygame.DOUBLEBUF | pygame.OPENGL)
    pygame.display.set_caption("Traffic Jam")
    clock = pygame.time.Clock()
    done = False
    
    glMatrixMode(GL_PROJECTION)
    glLoadIdentity()
    width, height = viewport
    gluPerspective(90.0, width/float(height), 1, 300.0)

    ## LUZ
    glEnable(GL_LIGHTING)
    # LUZ 0
    glEnable(GL_LIGHT0)
    glLightfv(GL_LIGHT0, GL_POSITION,  (0.0, 8, 0.8, 1.0))
    glLightfv(GL_LIGHT0, GL_AMBIENT, (0.1, 0.1, 0.1, 0.0))
    glLightfv(GL_LIGHT0, GL_DIFFUSE, (1, 1, 1, 1.0))
    glLightfv(GL_LIGHT0, GL_SPECULAR, (1, 1, 1, 1.0))

    # LUZ 1
    glEnable(GL_LIGHT1)
    glLightfv(GL_LIGHT1, GL_POSITION,  (0, 0, 1, 0))

    ## REST
    glEnable(GL_COLOR_MATERIAL)
    glEnable(GL_DEPTH_TEST)
    glShadeModel(GL_SMOOTH)

    scene = Scene()

    # Main Loop
    while not done:
        
        for event in pygame.event.get(): 
            if event.type == pygame.QUIT:  
                done = True 

        if event.type == pygame.KEYDOWN:
            if event.key == pygame.K_RIGHT or event.key == pygame.K_d:
                scene.car.move_right()
                scene.car.rotate_right()
            elif event.key == pygame.K_LEFT or event.key == pygame.K_a:
                scene.car.move_left()
                scene.car.rotate_left()
            elif scene.game_over and event.key == pygame.K_r:
                scene = Scene()

        if event.type == pygame.KEYUP:
            if event.key == pygame.K_LEFT or event.key == pygame.K_a:
                scene.car.rotate = 0
            elif event.key == pygame.K_RIGHT or event.key == pygame.K_d:
                scene.car.rotate = 0
        if not scene.game_over:
            scene.render_scene()
            scene.update(SPEED_RATE)
            pygame.display.flip()
        elif scene.game_over:
            print "Pressione R, para reiniciar"
            
        clock.tick(60)
    pygame.quit()


if __name__ == "__main__":
    main()
