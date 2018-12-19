<?php

class TCP
{
	private $ip;
	private $port;
	private $Requete;
	private $socket;
	private $resultat;
	
	
	
	public function __construct($IP,$PORT,$REQUETE) 
	
	{
		
		// On Stocke les informations de connexion
		$this->ip=$IP;
		$this->port=$PORT;	
		$this->Requete=$REQUETE;
		
		// Création du Socket
		$this->socket = socket_create(AF_INET, SOCK_STREAM, 0);
		
		$this->Envoi();
		$this->Reception();
		$this->Deconnexion();
		
	}
	
	private function Envoi()
	{
		// Le Socket se connecte
		$this->resultat = socket_connect($this->socket, $this->ip, $this->port);
		
		// On écrit sur le Socket
		socket_write($this->socket, $this->Requete, strlen($this->Requete));
		
			
		
		
	}
	
	
	private function Reception()
	{
		
		$this->resultat = socket_read ($this->socket,1024,PHP_NORMAL_READ) ;
		
	
	}
	
	private function Deconnexion()
	{
		
			socket_close($this->socket);
		
	}
	
	public function RecupererResultat()
	{
		
			return $this->resultat;
		
	}
	
	
	
};




?>