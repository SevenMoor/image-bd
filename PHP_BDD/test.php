<?php
	include 'OCIConnection.php';

	$OCICon = OCIConnection::getConnection();
	if (!$OCICon) {
		print 'oci = null<br/>';
	}
	else {
		print 'oci != null<br/>';
		if (!$OCICon->_connection) {
			print 'connection = null<br/>';
		}
		else {
			print 'connection != null<br/>';
		}

	}

	$parsed = oci_parse($OCICon->_connection, "select * from similaire order by dist asc;");
	var_dump(oci_execute($parsed));

?>
