const trilho = document.getElementById("trilho");

const ctx = document.getElementById('grafico').getContext('2d');
const chartSom = new Chart(ctx, {
    type: 'line',
    data: {
            labels: [], // Eixo X (Tempo)
            datasets: [{
                    label: 'Nível de Ruído (dB)',
                    data: [], // Eixo Y (Valores)
                    borderColor: '#ff9800',
                    backgroundColor: 'rgba(255, 152, 0, 0.2)',
                    borderWidth: 2,
                    fill: true,
                    tension: 0.3 // Suaviza a linha
               }]
          },
     options: {
          responsive: true,
          maintainAspectRatio: false,
          scales: {
               y: {
                    min:30,
                    max:120,
                    ticks: { color: '#aaaaa' }
               },
               x: {
                    ticks: { display: false } 
               }
          },
          aniamtion: {duration: 0}
     }
});  



const map = L.map('mapa').setView([-25.4297, -49.2719], 15); 

L.tileLayer('https://{s}.tile.openstreetmap.org/{z}/{x}/{y}.png', {
    attribution: '© OpenStreetMap contributors'
}).addTo(map);

let heat = L.heatLayer([], {radius: 50, blur: 15, maxZoom: 17}).addTo(map);




function atualizarDashboard() {
    fetch('/ruido')
       .then(resposta => resposta.text())
       .then(valor => {
            const num = parseFloat(valor);
            
            const element = document.getElementById("valor_som");
            if(element) element.innerText = num;

            const agora = new Date().toLocaleTimeString(); // TimeString é melhor para segundos
            chartSom.data.labels.push(agora);
            chartSom.data.datasets[0].data.push(num);

            if(chartSom.data.labels.length > 20) {
                chartSom.data.labels.shift();
                chartSom.data.datasets[0].data.shift();
            }
            chartSom.update('none'); // 'none' evita animações pesadas para o ESP32

            atualizarMapa(num);
       })
       .catch(erro => console.error('Erro ao obter dados:', erro));
}

function atualizarMapa(db) {
    // Simulando uma nuvem que muda de intensidade com o som
    // Em um sistema real, você teria a posição GPS do sensor
    const intensidade = db / 120; // Normaliza entre 0 e 1
    heat.setLatLngs([[-25.4297, -49.2719, intensidade]]);
}





function irParaAba(indice) {
     const deslocamento = indice * -33.33;

     trilho.style.transform = `translateX(${deslocamento}%)`;
}




setInterval(atualizarDashboard, 500);