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

    /////////////////////////////////////////////////////////////////////////////////////////////////////////

    1) Compute forces
    2) Second Law of Newton F= m*a   a = 1/m * (all the forces computed in first step)
    3) Integrate -> verlet v2=v1+a*dt , x2 = x1+v1*dt+0.5 ...
    4) Collision

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    Grafics Engyne      We want them to run at the same time, same framerate
    Physics Engyne 



    Fixed delta time

    double t = 0;
    double dt = 1.0 / 60.0;


    Game Loop
    {
    //start a time counter
    tic();

    integrate (posvel,t,dt);
    t+=dt;
    telapsed = toc();

    if (dt -telapsed > 0.00) sleep (dt - telapsed);

    }

    Try tu run it in real time, if not FUIM it


    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    // To Code a physics engyne

    1- COMPUTE FORCES: Fgravity, Fdrag, F
    2- Newton 2nd law: everything tend to maintain his movement, F = mass * acceleration     
                       a -> change in velocity -> change position
    3- Integrations (Velocity Verlet integration method, STORMER Verlet) 
                                                                         x = v1 d t + 0.5 v2 - v1 d t^2 Velocity
                                                                         x = ((x1-x2)/dt) d t + 0.5 v2 - v1 d t^2 Stormer
    4- Collisions


    Fgravity = -mass * gravity
    Momentum = m * v

    How to start --> spoil

    class ball
    {
    position
        double x, y;
    velocity
        double vx,vy;
    acceleration
        double ax,ay;
    force
        double fx,fy;
    mass
        double mass;
    Aerodynamics force
        double surface;
        double cd;
    Has physics enable?
    bool isPhysicsEnabled;
    }

   
    void moduleScene::Start()
    {
        Ball ball;
        ball.isPhysicsEnabled = true;

        ball.mass = 10;
        ball.surface = 5;
        ball.cd = 0.1;

        ball.x=0.0;
        ball.y=0.0;

        ball.vx=10.0;
        ball.vy=5.0;


    }

    void Update()
    {
     #Step 0
      ball.fx = ball.fy = 0.0; 
      ball.ax = ball.ay = 0.0;

     #Step 1
      double fgx = ball.mass * 0.0;
      double fgy = ball.mass * -9.81;

      ball.fx += fgx;
      ball.fy += fgy;

      double speed = ball.speed(ball.vx, ball.vy);
      double fdx;
      double fdy;

      ball.fx += fdx;
      ball.fy += fdy;

    #Step 2 2nd N law

     double inv_mass= 1.0 / ball.mass;
     ball.ax = ball.fx * inv_mass;
     ball.ay = ball.fy * inv_mass;

    #Step 3 Integration
    //velocity verlet
     ball.x += ball.vx * dt +0.5*ball.ax*dt*dt;
     ball.y += ball.vy * dt +0.5*ball.ay*dt*dt;
     ball.vx += ball.ax * dt;
     ball.vy += ball.ay * dt;

     make it in a function void integration_velocity_verlet(ball *ball)

     #Step 4 solve collisions




    }

    At every frame:
    1 Player input
    2 game logic
    3 physics (farces, F=m*a, integrate, collisions)
    4 GFX

    You can do multithreading with them

    momentum before collision = ma *va +mb *vb;
    momentum after collision = ma *va +mb *vb; // do not know velocityes

    If momentum is constant = 0 -> momentum before = momentum after

    Energy mechanical = 0 -> Ekinetic 0.5*m*v*v + Epotential Depends if springs or gravity...
    
    before = Ek = 0.5*ma*va*va +0.5*mb*vb*vb;
    after = Ek = 0.5*ma*va*va +0.5*mb*vb*vb; // velocity changes

    conservation of mechanical energy

    get va after anda vb after

    main issue: we assume that the collision is elastic

    FUYM, multiply by a number lower than 1 and higher than 0 , we multiply after va or/and vb

    after v'a=va*0.5 per example coeficient of restitution

    solve collisions:

    ////////////////////////////////////////////////////////////////////////////////

    Ball in a wall 

    one force is perpendiclar to the face of the object
    another force in axis x paralel to the object face

    v'a->x = va * coeficient of friction
    v'a->y = va * coeficient of restitution

    rotation = cos angle  -sin angle
               sin angle  cos angle

               v'a (local world) = rotation of -angle * va (in original world)
               apply changes of velocity
               then rotate everything by angle

    Positions solvers:
    - Do not solve it
    - take pos 1 and 2, then tp the object outside and apply velocity and stuff on him
    - Do ray tracing, tp to the last non collision position and apply stuff

    ///////////////////////////////////////////////////////////////////////////////

    Gravity:

    //Gravity = (mass1 * mass2)/r*r

    Force g = -G * ((mass1 * mass2)/r*r)

    Force g = constant

    Force g = linear

    Force g = scale down


    
































































*/
