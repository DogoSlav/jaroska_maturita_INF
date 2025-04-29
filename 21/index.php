<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <h1>hello xd</h1>

    <!-- Tady tento kod dostaneme upravime jen dbname, select * FROM ... a pohrajeme si s while funkci -->
    <!-- vytvoril jsem databazi zoo, v tom tabulku zvirata, 3 polozky ID s auto_increment, nazev souboru (soubor) a popis -->
    <?php
        $kam = 'mysql:host=localhost;dbname=zoo';
        $uzivatel = 'root';
        $heslo = '';
        //pripoj se k serveru a zvol databazi
        $databaze = new PDO($kam, $uzivatel, $heslo);
        //priprav si dotaz v SQL
        $dotaz = $databaze->prepare("select * FROM zvirata");
        //posli dotaz do serveru
        $dotaz->execute();
        //do $row dej dalsi nezpracovany radek odpovedi
        while($radek = $dotaz->fetch()){
            //tiskni obsah pole s názvem ‘jmeno’

            echo "<a href = 'foto/".$radek['soubor']."'>".$radek['popis']."</a><br/>";
        }
    ?>

</body>

</html>