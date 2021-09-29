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



























































































*/
