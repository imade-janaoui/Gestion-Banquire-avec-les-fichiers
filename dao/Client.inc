<?php 
error_reporting(0);
echo' <head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="../gui/css/style1.css">
    <title>gestion bancaire</title>
</head>
<body>
<a href="../gui/AjouterClient.html" class="buttom">Home</a>
</body>
';
      function nouveauclient($Nom,$Prenom,$Adresse,$CIN)
      {
          $fp=fopen("../ressourses/client.txt","a");
          $ligne= $CIN .";". $Prenom .";".$Nom. ";" .$Adresse.";". "\r";
          fputs($fp,$ligne);
          fclose($fp);

      }
    function nouveaucompte($CIN,$numcompte,$Montant)
      {
        
        $fp=fopen("../ressourses/compte.txt","a");
        $ligne= $numcompte.";".$CIN.";".$Montant.";"."\r";
        fputs($fp,$ligne);
        fclose($fp);

    }

    
      function existeclient($CIN)
  {
   $fp=fopen("../ressourses/client.txt","r");
   $trouve=0;
   while(!feof($fp) && (!$trouve))
   {
      $ligne=fgets($fp,255);
      $row=explode(";",$ligne);
               if($row[0]==$CIN)
               { 
                $trouve=1;
                }
              
   }
          fclose($fp);
        return $trouve;
  }

  function existecompte($numcompte)
  {
   $fp=fopen("../ressourses/compte.txt","r");
   $trouve=0;
   while(!feof($fp) && (!$trouve)){
      $ligne=fgets($fp,255);
      $row=explode(";",$ligne);
         
                if($row[0]==$numcompte){ 
                $trouve=1;
                 }
                
 }
 fclose($fp);
 return $trouve; 
     
  }
    

    
  function virement($numcompte,$x)
  {
        $fp=fopen("../ressourses/compte.txt","r");
        $fn=fopen("../ressourses/comptenew.txt","a");
          while(!feof($fp))
          {
            $ligne=fgets($fp,255);
          $row=explode(";",$ligne);
                
                      if($row[0]==$numcompte)
                      {
                        $row[2]= $row[2]+$x;
                        $ligne=$row[0].";".$row[1].";".$row[2]."\r";
                    
                      }  
                      fputs($fn,$ligne);
                              
          }
            fclose($fp);
            fclose($fn);
            $fp=fopen("../ressourses/compte.txt","w");
            $fn=fopen("../ressourses/comptenew.txt","r");
              while(!feof($fn) ){
                $ligne=fgets($fn,255);
                fputs($fp,$ligne);
                                  
              }
              fclose($fp);
            fclose($fn);
        }

        function infos($CIN)
        {
              $fp=fopen("../ressourses/client.txt","r");
              while(!feof($fp) ){
                    $ligne=fgets($fp,255);
                    $row=explode(";",$ligne);
                    if ($row[0]==$CIN){
                      echo ("
                         <div>
                         <table >
                              <tr>
                                   <th>Prenom</th>
                                   <th>Nom</th>
                                </tr>
                                <tr>
                                    <td>$row[1]</td>
                                    <td>$row[2]</td>
                                </tr>
                            </table>
                            </div>");
                    }else{
                      echo "<script> alert('ce client est n\'existe pas')";
                    }
                }
                  fclose($fp);
                $fp=fopen("../ressourses/compte.txt","r");
              while(!feof($fp) ){
                $ligne=fgets($fp,255);
                $row=explode(";",$ligne);
                if ($row[1]==$CIN){
                  echo ("<div>
                        <table >
                              <tr>
                                   <th>Numero de Compte</th>
                                   <th>Montant</th>
                                </tr>
                                <tr>
                                    <td>$row[0]</td>
                                    <td>$row[2]</td>
                                </tr>
                            </table>
                            </div>");
                  
                }
            }
            fclose($fp);
        }




  function supprimer($CIN)  
    {
        $fp=fopen("../ressourses/compte.txt","r");
        $fn=fopen("../ressourses/comptenew.txt","w");
          while(!feof($fp))
          {
            $ligne=fgets($fp,255);
          $row=explode(";",$ligne);
                
                      if($row[1]==$CIN)
                      {
                        
                          unset($ligne);
                    
                      }  
                      fputs($fn,$ligne);
                              
          }
        fclose($fp);
        fclose($fn);
        $fp=fopen("../ressourses/compte.txt","w");
        $fn=fopen("../ressourses/comptenew.txt","r");
          while(!feof($fn) ){
            $ligne=fgets($fn,255);
            fputs($fp,$ligne);
                              
          }
          fclose($fp);
        fclose($fn);


        $fp=fopen("../ressourses/client.txt","r");
        $fn=fopen("../ressourses/comptenew.txt","w");
          while(!feof($fp))
          {
            $ligne=fgets($fp,255);
            $row=explode(";",$ligne);
                
                      if($row[0]==$CIN)
                      {
                        
                          unset($ligne);
                    
                      }  
                      fputs($fn,$ligne);
                              
          }
        fclose($fp);
        fclose($fn);
        $fp=fopen("../ressourses/client.txt","w");
        $fn=fopen("../ressourses/comptenew.txt","r");
          while(!feof($fn) ){
            $ligne=fgets($fn,255);
            fputs($fp,$ligne);
                              
          }
          fclose($fp);
        fclose($fn);
     }


     function Débiteurs($CIN)
     {
        
              $fp=fopen("../ressourses/client.txt","r");
              $fn=fopen("../ressourses/compte.txt","r");
              while(!feof($fp) ){
                    $ligne=fgets($fp,255);
                    $ligne1=fgets($fn,255);
                    $row=explode(";",$ligne);
                    $row1=explode(";",$ligne1);
                    if ($row[0]==$CIN && $row1[1] ){
                     
                     if(row1[2]<=0)
                     { echo ("
                         <div>
                         <table >
                              <tr>
                                   <th>Prenom</th>
                                   <th>Nom</th>
                                </tr>
                                <tr>
                                    <td>$row[1]</td>
                                    <td>$row[2]</td>
                                </tr>
                            </table>
                            </div>");
                     }
                    }
                }

     }
?> 


