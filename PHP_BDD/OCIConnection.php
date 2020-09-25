<?php
	class OCIConnection {
		/**
		* @var Singleton
		* @access private
		* @static
		*/
		private static $_ociConnection = null;
		public $_connection = null;

		/**
		*
		* Constructeur de la classe
		*
		* @param void
		* @return void
		*/
		private function __construct() {
			$this->_connection = oci_connect("Y2020M2_PAUQUET", "M123456M", "//10.40.128.30:1521/orcl");
			/*if (!$this->_connection) {
				$m = oci_error();
				echo $m['message'], "\n";
				exit;
			}
			else {
				echo 'Connected!';
			}*/
		}

		private function __destruct() {
			if ($this->_connection) {
				oci_close($this->_connection);
			}
		}

		/**
		* Méthode qui crée l'unique instance de la classe
		* si elle n'existe pas encore puis la retourne.
		*
		* @param void
		* @return OCIConnection
		*/
		public static function getConnection() {
			if(is_null(self::$_ociConnection)) {
				self::$_ociConnection = new OCIConnection();
			}
			return self::$_ociConnection;
		}
	}
?>
