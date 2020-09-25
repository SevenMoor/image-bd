<?php
	class OCIConnection {
		/**
		* @var Singleton
		* @access private
		* @static
		*/
		private static $_connection = null;

		/**
		*
		* Constructeur de la classe
		*
		* @param void
		* @return void
		*/
		private function __construct() {  
			$conn = oci_connect("Y2020M2_PAUQUET", "M123456M", "//10.40.128.30:1521/orcl");
			if (!$conn) {
				$m = oci_error();
				echo $m['message'], "\n";
				exit;
			}
			else {
				print "Connected to Oracle!";
			}
		}

		private function __destruct() {
			oci_close($_connection);
		}

		/**
		* Méthode qui crée l'unique instance de la classe
		* si elle n'existe pas encore puis la retourne.
		*
		* @param void
		* @return OCIConnection
		*/
		public static function getConnection() {
			if(is_null(self::$_connection)) {
				self::$_instance = new OCIConnection();  
			}

			return self::$_instance;
		}
	}
?>
