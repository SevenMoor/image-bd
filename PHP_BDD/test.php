<?php
	include 'OCIConnection.php';

	ini_set('display_errors', 1);
	ini_set('display_startup_errors', 1);
	error_reporting(E_ALL);

	$OCICon = OCIConnection::getConnection();
	var_dump($OCICon);

	echo '<br/><br/>Requete <br/>';
	$parsed = oci_parse($OCICon->_connection, "begin ranker_(:p); end;");
	$jpg = "1.jpg";
	oci_bind_by_name($parsed,':p', $jpg, 50, SQLT_CHR);
	var_dump(oci_execute($parsed));

	var_dump(oci_error());
?>
