let ol=document.getElementById("menu")
let lastSelected=null;
let eles=ol.getElementsByTagName("li")

for(let i=0;i<eles.length;i++)
{
eles[i].addEventListener('click',($event)=>{
   if(lastSelected!=null)
   lastSelected.classList.remove("selected")

   $event.toElement.classList.add("selected")
   lastSelected= $event.toElement
})
}

