 		function loggingjs(){
 			var login=document.getElementById("login").value;
 			var password=document.getElementById("password").value;
 			if(login=="JakubKivi" && password=="KNI"){
 				document.getElementById("loged").innerHTML="Zalogowano";
 				document.getElementById("wrong").innerHTML="";
 			}
 			else 
 				document.getElementById("wrong").innerHTML="Zły Login lub hasło";
 		}

 		function clockF(){
 			var date= new Date();

 			var day = date.getDate();
 			var month = date.getMonth()+1;
 			var year = date.getFullYear();

 			var hours = date.getHours();
 			var minutes = date.getMinutes();
 			var seconds = date.getSeconds();

 			document.getElementById("clock").innerHTML =
 			day+"/"+month+"/"+year+"  "+hours+":"+minutes+":"+seconds;

 			setTimeout("clockF()", 1000);
 		}