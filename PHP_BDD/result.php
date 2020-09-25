<!doctype html>
<html lang="fr">
  <?php
    ini_set('display_errors', 1);
    ini_set('display_startup_errors', 1);
    include('OCIConnection.php');
    error_reporting(E_ALL);


    $connection = OCIConnection::getConnection();
    $statement = oci_parse($connection,"EXECUTE ranker('".$_GET["name"]."')");
    oci_execute($statement);
    oci_commit($connection);
    oci_free_statement($statement);

    $statement = oci_parse($connection,"SELECT * FROM similaire ORDER BY dist ASC LIMIT 10");
    oci_execute($statement);
    oci_commit($connection);
  ?>

  <head>
    <!-- Required meta tags -->
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">

    <!-- Bootstrap CSS -->
    <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.5.2/css/bootstrap.min.css" integrity="sha384-JcKb8q3iqJ61gNV9KGb8thSsNjpSL0n8PARn9HuZOnIxN0hoP+VmmDGMN5t9UJ0Z" crossorigin="anonymous">
      <link href="https://fonts.googleapis.com/css2?family=Roboto:wght@100&display=swap" rel="stylesheet">

    <title>Atelier Indexation - Interface</title>
  </head>
  <body>
    <h1 class="display-1 text-center font-weight-light" style="font-family: 'Roboto', sans-serif !important;">Images similaires</h1>
    <hr>
    <div class="row justify-content-md-center">
        <?php
            echo "<img src='archive500/$_GET[name]' class='img-fluid shadow rounded' alt='$_GET[name]'>";
        ?>
    </div>
    <div class="row justify-content-md-between align-items-center mx-3">
        <?php
          while(oci_fetch($stid)){
            echo "<a role='button' class='btn btn-light mb-2' href='result.php?name=$i.jpg'>
                        <img src='archive500/".oci_result($statement,"nom")."' class='img-fluid shadow rounded' alt='".oci_result($statement,"nom")."'>
                        <span class='text-muted text-center w-100 sm'>Score de distance:".oci_result($statement,"dist")."</span>
                      </a>";
          }
        ?>
    </div>

    <!-- Optional JavaScript -->
    <!-- jQuery first, then Popper.js, then Bootstrap JS -->
    <script src="https://code.jquery.com/jquery-3.5.1.slim.min.js" integrity="sha384-DfXdz2htPH0lsSSs5nCTpuj/zy4C+OGpamoFVy38MVBnE+IbbVYUew+OrCXaRkfj" crossorigin="anonymous"></script>
    <script src="https://cdn.jsdelivr.net/npm/popper.js@1.16.1/dist/umd/popper.min.js" integrity="sha384-9/reFTGAW83EW2RDu2S0VKaIzap3H66lZH81PoYlFhbGU+6BZp6G7niu735Sk7lN" crossorigin="anonymous"></script>
    <script src="https://stackpath.bootstrapcdn.com/bootstrap/4.5.2/js/bootstrap.min.js" integrity="sha384-B4gt1jrGC7Jh4AgTPSdUtOBvfO8shuf57BaghqFfPlYxofvL8/KUEfYiJOMMV+rV" crossorigin="anonymous"></script>
  </body>
</html>