#pragma once

/*

Fake it until you make it! ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

- Ancestors

  plant mooves in function of where the player is (point in the middle of the plant, that goes to the middle of the player)
  Hitbox player / hitbox plant --> simple tranformation, detect collision --> get distance between center --> transformation on the model

  monkey slides down... how unexpected. Justify the kinetic enegy (bounce or slide, or break)
  jump --> aply a function that slides you down --> What is the input?  Horizontal(not accurrate, doesn't adapt to the situation) 
  Velocity? more precise, Vy Vx for bouncing and Vz distance slide

- ABZÛ

  plants --> move away
  a compound object with joints, rotate the nodes in collision with the player and the lines still constant
  The camera collides as well

- Euclidian / Non Euclidian

  Euclidian / Eliptical / Hiperbolic

- HellBlade 

  Portals

- Manifall Garden

  Infinite map == teleporting upwards

- Superliminal

  The size of the cube and his size on the screen is the same, so it calculates the max distance on the space 
  that makes it change its size

- EVE Online
  
  Bullshit Engine

  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  TODOs:

  1) Make a ground, then a plant and a player, the plant must modify in function of the distance

  2) Make a ground, 2 portals, 1 intaque and 1 out take, add textures to make it funny

  //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  LINEAR MOVEMENT

  x --> position: simply the position of the object in the space
  v --> velocity: (a hard limit, speed of light) how quickly the objects moove
  a --> acceleration: velocity variation

  ANGULAR MOVEMENT

  º --> position: what is his orientation
  w --> velocity: the change of orientation
  & --> acceleration: change the velocity of the angle
  
  3 Newton's Laws:

  - An object in motion stays in motion until an external force change his state (Inertia / momentum)

  - LINEAR MOMENTUM:
     Real momentum = mass * velocity ----- Videogames momentum = velocity (FUYM, ok beacose the mass is constant)
  - ANGULAR MOMENTUM:
     Inertia * angular velocity
  - If a force is aplied to an object, the acceleration of this one is going to change
    F = m * a
    Tork = I * &

  - Every force has an inverse gravity + -gravity = 0, you do not move

  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    Integration --> Change with derivatives and integrals

    Integration Methods:

    EULER methods: // First order integrators

    Forward 
    - For next frame: Body.x = Body.x + (velocity * delta time) // Kinda unprecise, used for smooth movement, it assume the velocity is constant

    Backwards
    - For last frame: Body.x = Body.x + (velocity * delta time)

    Verlet methods: // Second order integrators

    - Velocity Verlet Method: Area = (velocity1*deltatime) + 0.5 * deltatime * (velocity2 * velocity1)

    - STORMER Verlet Method...

    Runge Kuta (really expensive and accurrate)






















































































*/
