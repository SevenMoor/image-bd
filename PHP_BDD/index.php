<!doctype html>
<html lang="fr">
  <?php 
    ini_set('display_errors', 1);
    ini_set('display_startup_errors', 1);
    error_reporting(E_ALL);
  ?>

  <head>
    <!-- Required meta tags -->
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">

    <!-- Bootstrap CSS -->
    <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.5.2/css/bootstrap.min.css" integrity="sha384-JcKb8q3iqJ61gNV9KGb8thSsNjpSL0n8PARn9HuZOnIxN0hoP+VmmDGMN5t9UJ0Z" crossorigin="anonymous">
      <link href="https://fonts.googleapis.com/css2?family=Roboto:wght@100&display=swap" rel="stylesheet">
      <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.5.1/jquery.min.js"></script>
      <title>Atelier Indexation - Interface</title>
  </head>
  <body>
    <h1 class="display-1 text-center font-weight-light" style="font-family: 'Roboto', sans-serif !important;">Base d'images</h1>
    <hr>
    

    <nav class="navbar navbar-expand-lg navbar-light rounded bg-light m-3">
  <a class="navbar-brand" href="#">Joogle Search Engine</a>
  <button class="navbar-toggler" type="button" data-toggle="collapse" data-target="#navbarSupportedContent" aria-controls="navbarSupportedContent" aria-expanded="false" aria-label="Toggle navigation">
    <span class="navbar-toggler-icon"></span>
  </button>

  <div class="collapse navbar-collapse" id="navbarSupportedContent">
    <ul class="navbar-nav mr-auto">
      <li class="nav-item dropdown">
        <a class="nav-link dropdown-toggle" href="#" id="navbarDropdown" role="button" data-toggle="dropdown" aria-haspopup="true" aria-expanded="false">
          Sélectionner la fonction de distance
        </a>
        <div class="dropdown-menu" aria-labelledby="navbarDropdown">
          <a class="dropdown-item" href="#" onclick="useRanker();">Générique (par défaut)</a>
          <a class="dropdown-item" href="#" onclick="useBlackwhite();">Critères Noir et blanc</a>
          <a class="dropdown-item" href="#" onclick="useGetoracle();">Fonctionnalités Oracle</a>
          <a class="dropdown-item" href="#" onclick="useGetrgb();">Critères de couleur (+rouge/-vert)</a>
          <a class="dropdown-item" href="#" onclick="useGettexture();">Critères de texture</a>
          <a class="dropdown-item" href="#" onclick="useGetblue();">Images les plus bleues</a>
        </div>
      </li>
    </ul>
  </div>
</nav>


    <div class="row justify-content-md-between align-items-center mx-3">
        <?php
        for ($i = 1; $i <= 500; $i++) {
            echo "<a role='button' class=' img-cont btn btn-light mb-2' href='result.php?name=$i.jpg&func=ranker_'>
                <img src='archive500/$i.jpg' class='img-fluid shadow rounded' alt='$i.jpg'>
              </a>";
        }
        ?>
    </div>

    <!-- Optional JavaScript -->
    <!-- jQuery first, then Popper.js, then Bootstrap JS -->
    <script src="https://code.jquery.com/jquery-3.5.1.slim.min.js" integrity="sha384-DfXdz2htPH0lsSSs5nCTpuj/zy4C+OGpamoFVy38MVBnE+IbbVYUew+OrCXaRkfj" crossorigin="anonymous"></script>
    <script src="https://cdn.jsdelivr.net/npm/popper.js@1.16.1/dist/umd/popper.min.js" integrity="sha384-9/reFTGAW83EW2RDu2S0VKaIzap3H66lZH81PoYlFhbGU+6BZp6G7niu735Sk7lN" crossorigin="anonymous"></script>
    <script src="https://stackpath.bootstrapcdn.com/bootstrap/4.5.2/js/bootstrap.min.js" integrity="sha384-B4gt1jrGC7Jh4AgTPSdUtOBvfO8shuf57BaghqFfPlYxofvL8/KUEfYiJOMMV+rV" crossorigin="anonymous"></script>

      <script>
        function useRanker(){
            $("a.img-cont").attr("href",$("a.img-cont").attr("href").replace(/func=(.*)/g,"func=ranker_"));
        }
        function useBlackwhite(){
          $("a.img-cont").attr("href",$("a.img-cont").attr("href").replace(/func=(.*)/g,"func=blackwhite"));
        }
        function useGetoracle(){
          $("a.img-cont").attr("href",$("a.img-cont").attr("href").replace(/func=(.*)/g,"func=getoracle"));
        }
        function useGettexture(){
          $("a.img-cont").attr("href",$("a.img-cont").attr("href").replace(/func=(.*)/g,"func=gettexture"));
        }
        function useGetrgb(){
          $("a.img-cont").attr("href",$("a.img-cont").attr("href").replace(/func=(.*)/g,"func=getrgb"));
        }
        function useGetblue(){
          $("a.img-cont").attr("href",$("a.img-cont").attr("href").replace(/func=(.*)/g,"func=getblue"));
        }
      </script>

  </body>
</html>