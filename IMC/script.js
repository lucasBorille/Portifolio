

function calcular(){
    var nome = document.getElementById("nome");
    var altura = document.getElementById("altura");
    var peso = document.getElementById("peso");
    var imc = peso.value/(altura.value**2);
    {if(imc<16.9){
        estado = 'muito abaixo do peso';
    }else if(imc<18.4){
        estado = 'abaixo do peso';
    }else if(imc<24.9){
        estado = 'com peso normal';
    }else if(imc<34.9){
        estado = 'acima do peso';
    }else{
        estado = 'obeso';
    }}
    document.getElementById("resultado").innerHTML=`${nome.value} seu IMC é ${imc.toFixed(1)} e você está ${estado}`
}