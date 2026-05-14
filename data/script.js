
function atualizarRuido(){
    fetch('/ruido')
       .then(resposta => resposta.text()) 
       .then(valor => { 
            document.getElementsByName("valorRuido").innerText = valor;
       })
       .catch(erro => console.error('Erro ao obter o valor do ruido :'))


}

setInterval(atualizarRuido, 500);