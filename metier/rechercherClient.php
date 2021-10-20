<?php
include "../dao/Client.inc";
if(isset($_POST['submit5'])){
    $cin=$_POST['CIN'];
    if (existeclient($cin)==0){
        echo"<script> alert('ce client est n\'existe pas ')</script>";
    }else{
        echo"<script> alert('ce client est déjà existe ')</script>";
    }
    
}
?>