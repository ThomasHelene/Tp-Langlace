<?php

class TCP
{
	private $ip;
	private $port;
	private $Requete;
	private $socket;
	private $resultat;
	private $EtatConnexion;
	
	
	
	public function __construct($IP,$PORT,$REQUETE) 
	
	{
		
		// On Stocke les informations de connexion
		$this->ip=$IP;
		$this->port=$PORT;	
		$this->Requete=$REQUETE;
		
		// Création du Socket
		$this->socket = socket_create(AF_INET, SOCK_STREAM, 0);
		
		$this->Envoi();
		if($this->EtatConnexion==true)
		{
			$this->Reception();
			$this->Deconnexion();
		}
		
	}
	
	private function Envoi()
	{
		
		// On teste la connexion
	
					
    error_reporting(E_ERROR | E_PARSE);
				$bool=socket_connect($this->socket,$this->ip,$this->port);

	
					
			
		
		if($bool==true)
		{
		$this->EtatConnexion=true;
		// On écrit sur le Socket
		socket_write($this->socket, $this->Requete, strlen($this->Requete));
		
		}
		else
		{
			
			$this->EtatConnexion=false;
			$this->resultat="N/A";
			echo"Serveur Meteo non disponible";
		}
		
	}
	
	
	private function Reception()
	{
		
		$this->resultat = socket_read ($this->socket,2048,PHP_NORMAL_READ) ;
		
	
	}
	
	private function Deconnexion()
	{
		
			socket_close($this->socket);
		
	}
	
	public function RecupererResultat()
	{
		
			return $this->resultat;
		
	}
	
	public function RecupererEtatConnexion()
	{
		
			return $this->EtatConnexion;
	}
	
	
	
};




?>