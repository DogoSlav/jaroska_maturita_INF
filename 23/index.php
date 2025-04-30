<!DOCTYPE html>
<html lang='cs'>
  <head>
    <title></title>
    <meta charset='utf-8'>
    <meta name='description' content=''>
    <meta name='keywords' content=''>
    <meta name='author' content=''>
    <meta name='robots' content='all'>
    <!-- <meta http-equiv='X-UA-Compatible' content='IE=edge'> -->
    <link href='/favicon.png' rel='shortcut icon' type='image/png'>
  </head>
  <body>
  <h1>
   Vyhledávání učitelů
  </h1>
  
  <form action="index.php" method="get">
  <label for="jmenoid">Jméno:</label><br>
  <input type="text" id="jmenoid" name="jmeno" value=""><br>
  <label for="prijmeniid">Příjmení:</label><br>
  <input type="text" id="prijmeniid" name="prijmeni" value=""><br>
  <label for="aprobaceid">Aprobace:</label><br>
  <input type="text" id="aprobaceid" name="aprobace" value=""><br><br>
  <input type="submit" value="Vyhledat">
  </form>
<?php
if (isset($_GET['jmeno'])){
    $kam = 'mysql: host=localhost;dbname=skola';
    $uzivatel = 'root';
    $heslo = '';
    //pripoj se k serveru a zvol databazi
    $databaze = new PDO($kam, $uzivatel, $heslo);
 
    //priprav si dotaz v SQL
    $dotaz = $databaze->prepare("SELECT * FROM skola WHERE prijimeni LIKE :prijmeni and jmeno LIKE :jmeno and predmet LIKE :aprob");
    $pole[':prijmeni']=$_GET['prijmeni']."%";
    $pole[':jmeno']=$_GET['jmeno']."%";
    $pole[':aprob']="%".$_GET['aprobace']."%";
    //posli dotaz do serveru
    $dotaz->execute($pole);
    //do $row dej dalsi nezpracovany radek odpovedi
    while($radek = $dotaz->fetch()){
        //tiskni obsah pole s názvem ‘jmeno’
        echo $radek['jmeno']." ".$radek['prijimeni']."<br/>";
        echo"<hr/>";
    }
}
?>
  </body>
</html>