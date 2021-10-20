<?php
include "../dao/Client.inc";
if(isset($_POST['submit4'])){
    $cin=$_POST['CIN'];
    
    supprimer($cin);
}
?>
