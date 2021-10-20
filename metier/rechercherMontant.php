<?php
include "../dao/Client.inc";
if(isset($_POST['submit6'])){
    $ncmt=$_POST['ncmt'];
    if (existecompte($ncmt)==0){
        echo"<script> alert('ce compte est n\'existe pas ')</script>";
    }else{
        echo"<script> alert('ce compte est déjà existe ')</script>";
    }
    
}
?>