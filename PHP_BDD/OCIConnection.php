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
			self::$connection = oci_connect("Y2020M2_PAUQUET", "M123456M", "//10.40.128.30:1521/orcl");
/*			if (!$conn) {
				$m = oci_error();
				echo $m['message'], "\n";
				exit;
			}*/
		}

		private function __destruct() {
			oci_close(self::$_connection);
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
				self::$_connection = new OCIConnection();
			}

			return self::$_connection;
		}
	}
?>
