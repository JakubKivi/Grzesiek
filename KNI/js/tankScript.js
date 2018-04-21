var plotno = document.getElementById("game");

/*window.addEventListener("resize",fnc);

fnc(){
	plotno.width=document.width||document.body.clientWidth||800;
	plotno.height=document.height||document.body.clientHeight||800
}
*/	




var ctx = plotno.getContext("2d");

ctx.fillStyle = "#00FF88";
ctx.fillRect(100, 100, 100, 250);

ctx.beginPath();
ctx.arc(150, 225, 40, 0, 2*Math.PI, false);
ctx.fillStyle= "GREEN";
ctx.fill();

ctx.beginPath();
ctx.moveTo(150, 225);
ctx.lineTo(150, 400);
ctx.strokeStyle="Green";
ctx.lineWidth = 14;
ctx.stroke();

var grad = ctx.createLinearGradient(150, 400, 150, 600);
grad.addColorStop(0, "Red");
grad.addColorStop(1, "Grey");

ctx.beginPath();
ctx.moveTo(150, 400);
ctx.bezierCurveTo(50, 500, 0,600, 150, 600);
//ctx.strokeStyle="Red";
//ctx.stroke();
ctx.fillStyle= grad;
ctx.fill();
ctx.moveTo(150, 400);
ctx.bezierCurveTo(200, 500, 300,600, 150, 600);
//ctx.strokeStyle="Red";
//ctx.stroke();
ctx.fillStyle= grad;
ctx.fill();

var gradient = ctx.createLinearGradient(15, 400, 150, 600);

for (var i = 0; i < 6; i++){
  for (var j = 0; j < 6; j++){
    ctx.fillStyle = 'rgb(' + Math.floor(255 - 42.5 * i) + ',' +
                     Math.floor(255 - 42.5 * j) + ',0)';
    ctx.fillRect(j * 25, i * 25, 25, 25);
  }
}




/*ctx.strokeStyle = "#adadad";
ctx.lineWidth=4;
ctx.stroke.Rect(10, 10, 100, 40);

ctx.beignPath();
ctx.moveTo(220, 10);
ctx.lineTo(300, 100);
ctx.lineWidth = 10;
ctx.strokeStyle="grey";
ctx.stroke();
*/