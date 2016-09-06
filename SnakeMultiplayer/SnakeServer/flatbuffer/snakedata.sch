namespace snakedata;
table point{
	x:int;
	y:int;
}
table snakebodydata{
	snakebody:[point];
	board:boarddata;
	snakefood:snakefooddata;
	gamestatus:string;
	gamescore:int;
}
table snakefooddata{
	x:int;
	y:int;
}
table boarddata{
	width:int;
	height:int;
}
root_type snakebodydata;