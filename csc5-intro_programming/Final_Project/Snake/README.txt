Jiwon Yoo
Professor Ung.
Snake Verson 1.0;
December 8, 2013.
ID : 2485776

DESCRIPTION:
	Snake is a game in which a ¡°snake¡± moves around the screen collecting pellets.
	 As each pellet is collected, the snake grows larger in size.

	Purpose of the game is to collect as many pellet without hitting a wall or
	snake's body itself.

	As snake collect pellets, snake moves faster and faster, but at certain point
	snake doesn't get any faster. Try to collect as many pellet as you can.

	There are three types of a pellet.
	1)	Good Pellet(red)
	2)	Bad Pellet(yellow)
	3)	Super Pellet(gray-ish)

	Good Pellet is a typical pellet that snake collects.
		 Worth 1 point.
		 Increase snake body by one.
		 Snake moves faster. 
	
	Bad Pellet is bad food.
		 Worth -1 point.
		 Decreases the size by one.
		 Snake moves slower.

	Super Pellet is a special pellet.
		When bad pellet generates in new location, for the first few mili-sec it becomes Super Pellet
			but after few mili-sec it turns back to bad pellet.
		Worth 2 points.
		Snake moves faster.

	When snake size is 1 (just the head), snake moves fairly slow and it wont be fair if player
	only eats the Super pellet. So Super Pellet's duration will be very short when snake's size
	is small; because snake moves slow. As snake eats a pellet and get larger, the duration will get longer.

	FASTER SNAKE = MORE OPPORTUNITIES TO GET POINTS!!



HOW TO PLAY :

	double click "snake.exe" on a folder called snake.
	
	when game is started, you'll see a START or QUIT menu to click with your mouse.
	
	click START to start the game or clikc QUIT to quit the game.

	Use Arrow keys to move.
	
	** snake can't move to the oppoisite direction of your snake's current movement.

	Ex) if snake is moving towards East, you can only change direction to North or South.
	     
	    if a player try to move direction directly from North to South, snake will continue moving to North
	    w/o changing the direction. 

WHAT WORKS :
	
	Collision with the wall.

	Collision with its own body.

	Collision with Good, Bad, Super Pellet.
	
	Automatic new location generator for Pellets. (if player can't eat Good, Bad, Super pellet in certain time, re-gen in new location.)

	Snake moving parts.
	
	Pellet does not generate where snakes bodies are.

	Stores current game scores to a file.
		1) number of Good Pellets that snake ate.
		2) number of Bad Pellets eaten. 
		3) number of Super Pellets eaten.
		4) Total points/score.
		5) Size of a snake.
		

WHAT NOT WORKS :
	
	Maximum number scoring. (It only scores the current games score to where the .EXE file is).










