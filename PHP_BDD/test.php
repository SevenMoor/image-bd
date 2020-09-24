<?php

	class OCIConnection {
	  /**
	   * @var Singleton
	   * @access private
	   * @static
	   */
	   private static $_instance = null;
	 
	   /**
	    *
	    * Constructeur de la classe
	    *
	    * @param void
	    * @return void
	    */
	   private function __construct() {  
	   }
	   /**
	    * Méthode qui crée l'unique instance de la classe
	    * si elle n'existe pas encore puis la retourne.
	    *
	    * @param void
	    * @return Singleton
	    */
	   public static function getInstance() {
	 
	     if(is_null(self::$_instance)) {
	       self::$_instance = new Singleton();  
	     }
	 
	     return self::$_instance;
	   }
	}

	// Create connection to Oracle
	// [//]host_name[:port][/service_name]
	$conn = oci_connect("Y2020M2_PAUQUET", "M123456M", "//10.40.128.30:1521/orcl");
	if (!$conn) {
	   $m = oci_error();
	   echo $m['message'], "\n";
	   exit;
	}
	else {
	   print "Connected to Oracle!";
	}
	// Close the Oracle connection
	oci_close($conn);
?>
