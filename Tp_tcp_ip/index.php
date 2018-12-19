<?php

	include "ClasseTCP.php";
	
		if(isset($_POST["envoi"]))
		{
			$tcp = new TCP("192.168.65.9","1024","temp");
			$temperature=$tcp->RecupererResultat();
			
		}
?>


<html>


	<head>
	<p>yolo</P>
		<meta charset="UTF-8">
	
	
	</head>



	<body>

		<center>
			
			<form method="post" action="index.php">

			<input type="submit" name="envoi" value="Obtenir la température" />

			</form>

		
		
		
			
			<div>
			
				<p id="temperature"> La température est égale à <?php if (isset($tcp)) echo $temperature;?>°C </p>
			
			
			</div>

		
		
		</center>
		
	</body>

</html>
