<?php
include "../dao/Client.inc";
if(isset($_POST['submit7'])){
    $cin=$_POST['CIN'];
    Débiteurs($cin);
}
?>