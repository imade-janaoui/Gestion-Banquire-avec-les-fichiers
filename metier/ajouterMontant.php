<?php
include "../dao/Client.inc";
if(isset($_POST['submit3'])){
    $ncmt=$_POST['ncmt'];
    $x=$_POST['x'];
    virement($ncmt,$x);
}

?>