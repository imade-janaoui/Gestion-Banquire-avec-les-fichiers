<?php 
include "../dao/Client.inc";
if(isset($_POST['submit1']))
{
        $P=$_POST['Prénom'];
        $N=$_POST['Nom'];
        $A=$_POST['Adresse'];
        $cin=$_POST['CIN'];
        $ncmt=$_POST['ncmt'];
        $M=$_POST['Montant'];


        if (existeclient($cin)==0)
        {
                    nouveauclient($N,$P,$A,$cin);
                if(existecompte($ncmt)==0 ){
                  Nouveaucompte($cin,$ncmt,$M);
                  echo"<script> alert('L\'inscription avec succès')</script>";
                
                }
                else{
                    echo"<script> alert('ce compte est déjà existe ')</script>";
                }
        }else
        {
            echo"<script> alert('ce client est déjà existe! Voulez-vous ajouter un nouveau compte? ')</script>";
            if(existecompte($ncmt)==0){
                Nouveaucompte($cin,$ncmt,$M);
                echo"<script> alert('L\'inscription avec succès')</script>";
                
            }else{
                echo"<script> alert('ce compte est déjà existe ')</script>";
                
                
            }
        }
}
 error_reporting(0);
?>