var plotno = document.getElementById("game");


var ctx = plotno.getContext("2d");


var x=document.width;
var y=document.height;

function drawMap(){
		ctx.moveTo(0, document.height/2);
		ctx.lineTo(document.width, document.heigh );
		ctx.lineWidth = 10;
		ctx.strokeStyle="red";
		ctx.stroke();
}


function resize(){
	plotno.width=document.width/2||document.body.clientWidth/2||800;
	plotno.height=document.height||document.body.clientHeight||800;
	ctx.moveTo(0, document.height/3||document.body.clientHeight/3);
	ctx.lineTo(document.width||document.body.clientWidth, document.heigh/3||document.body.clientHeight/3 );
	ctx.lineWidth = 10;
	ctx.strokeStyle="red";
	ctx.stroke();
	ctx.moveTo(0, document.height/3*2||document.body.clientHeight/3*2);
	ctx.lineTo(document.width||document.body.clientWidth, document.heigh/3*2||document.body.clientHeight/3*2 );
	ctx.stroke();
	ctx.moveTo(document.width/3||document.body.clientWidth/3, 0);
	ctx.lineTo(document.width/3||document.body.clientWidth/3, document.heigh||document.body.clientHeight );
	ctx.stroke();
	ctx.moveTo(document.width/6||document.body.clientWidth/6, 0);
	ctx.lineTo(document.width/6||document.body.clientWidth/6, document.heigh||document.body.clientHeight );
	ctx.stroke();
}

resize();


/*for (var i = 0; i < 6; i++){
  for (var j = 0; j < 6; j++){
    ctx.fillStyle = 'rgb(' + Math.floor(255 - 42.5 * i) + ',' +
                     Math.floor(255 - 42.5 * j) + ',0)';
    ctx.fillRect(j * 25, i * 25, 25, 25);
  }
}

ctx.strokeStyle = "#adadad";
ctx.lineWidth=4;
ctx.stroke.Rect(10, 10, 100, 40);

ctx.beignPath();
ctx.moveTo(220, 10);
ctx.lineTo(300, 100);
ctx.lineWidth = 10;
ctx.strokeStyle="grey";
ctx.stroke();
*/