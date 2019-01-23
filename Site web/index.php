<!DOCTYPE html>

<meta http-equiv="refresh" content="5" >
<meta charset="UTF-8">
<?php include('ClasseTCP.php') // on récup les données de la classe login.?>
<?php $TCP= new TCP("192.168.65.12",1024,"temp\n"); ?> 
<html>
	<head>
		<link rel="stylesheet" type="text/css" href="style.css" media="all"/>
		<title>Meteo</title>
	</head>
	<div class="banderole">
		<center>
			<fieldset>
 				<legend> <fieldset class="fieldsetitle"> Temperature actuelle : </fieldset> </legend>
					<div class="temperature">
						
						<?php echo $TCP->RecupererResultat(); echo "°C"; ?>
 						
 					</div>
 			</fieldset>
 			
 		</center>
	</div>
	<div class="bandeau">
		<br/>
		<br/>
	</div>



</html>