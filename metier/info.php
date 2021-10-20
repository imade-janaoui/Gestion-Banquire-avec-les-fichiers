<?php

include "../dao/Client.inc";
if(isset($_POST['submit2'])){
    $cin=$_POST['CIN'];
    infos($cin);
}

?>