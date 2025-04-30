<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
<?php
        $kam = 'mysql:host=localhost;dbname=miss';
        $uzivatel = 'root';
        $heslo = '';
        //pripoj se k serveru a zvol databazi
        $databaze = new PDO($kam, $uzivatel, $heslo);
        //priprav si dotaz v SQL
        $dotaz = $databaze->prepare("select * FROM soutezici");
        //posli dotaz do serveru
        $dotaz->execute();
        //do $row dej dalsi nezpracovany radek odpovedi

        if ($_SERVER['REQUEST_METHOD'] === 'POST'){
            $id = (int)$_POST['id'];
            $pricti = $databaze->prepare("UPDATE soutezici SET ph = ph + 1 WHERE ID = ?");
            $pricti->execute([$id]);
        }

        while($radek = $dotaz->fetch()){
            //tiskni obsah pole s názvem ‘jmeno’

            echo "<div>";
            echo $radek['jmeno']." ".$radek['prijimeni']." - pocet hlasu: ".$radek['ph'];
            echo "<form method='post'>";
                echo "<input type='hidden' name='id' value='".$radek['ID']."'>";
                echo "<input type='submit' value='Hlasovat'>";
            echo "</form>";
            echo "</div>";
        }
    ?>
</body>
</html>