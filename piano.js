window.addEventListener("keydown",(e)=>{
  console.log(e);
    console.log(e.keyCode);
    let selector=".key[data-ascii='"+e.keyCode+"']";
    // selector.classList.add("playing");
    let A=document.querySelector(selector);
    console.log(A); 
    let sname=A.querySelector("span").innerText;
    console.log(sname);
    let soun=document.createElement("audio");
    soun.setAttribute("src","./piano_sounds/"+sname+".wav");
    soun.play();
  })