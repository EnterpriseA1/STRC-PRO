const MARGIN = { LEFT: 100, RIGHT: 10, TOP: 10, BOTTOM: 100 };
const WIDTH = 800 - MARGIN.LEFT - MARGIN.RIGHT;
const HEIGHT = 500 - MARGIN.TOP - MARGIN.BOTTOM;

const svg = d3
  .select("#chart-area")
  .append("svg")
  .attr("width", WIDTH + MARGIN.LEFT + MARGIN.RIGHT)
  .attr("height", HEIGHT + MARGIN.TOP + MARGIN.BOTTOM);

const g = svg
  .append("g")
  .attr("transform", `translate(${MARGIN.LEFT}, ${MARGIN.TOP})`);

let carData;

// Tooltip
const tip = d3
  .tip()
  .attr("class", "d3-tip")
  .html((d) => {
    let text = `<strong>Model:</strong> <span style='color:red;text-transform:capitalize'>${d.model}</span><br>`;
    text += `<strong>Origin:</strong> <span style='color:red;text-transform:capitalize'>${d.origin}</span><br>`;
    text += `<strong>Year:</strong> <span style='color:red;text-transform:capitalize'>${
      1900 + +d.year
    }</span><br>`;
    text += `<strong>Cylinders:</strong> <span style='color:red;text-transform:capitalize'>${d.cylinders}</span><br>`;
    text += `<strong>Horsepower:</strong> <span style='color:red;text-transform:capitalize'>${d.horsepower}</span><br>`;
    text += `<strong>MPG:</strong> <span style='color:red;text-transform:capitalize'>${d.mpg}</span><br>`;
    text += `<strong>Weight:</strong> <span style='color:red;text-transform:capitalize'>${d.weight}</span><br>`;
    return text;
  });
g.call(tip);

// Scales
const x = d3.scaleLinear().range([0, WIDTH]).domain([40, 200]);
const y = d3.scaleLinear().range([HEIGHT, 0]).domain([10, 50]);

const area = d3
  .scaleLinear()
  .domain([0, 4000])
  .range([25 * Math.PI, 1500 * Math.PI]);
const OriginColor = d3.scaleOrdinal(d3.schemeCategory10);

// Labels
const xLabel = g
  .append("text")
  .attr("y", HEIGHT - 10)
  .attr("x", WIDTH - 35)
  .attr("font-size", "14px")
  .attr("text-anchor", "middle")
  .text("Horsepower");
const yLabel = g
  .append("text")
  .attr("y", 10)
  .attr("x", 20)
  .attr("font-size", "14px")
  .attr("text-anchor", "middle")
  .text("MPG");

// X Axis
const xAxisCall = d3
  .axisBottom(x)
  .ticks(8)
  .tickFormat((d) => (d === 40 ? "" : d));
g.append("g")
  .attr("class", "x axis")
  .attr("transform", `translate(0, ${HEIGHT})`)
  .call(xAxisCall);

// Y Axis
const yAxisCall = d3
  .axisLeft(y)
  .ticks(9)
  .tickFormat((d) => (d === 10 || d === 50 ? "" : d));
g.append("g").attr("class", "y axis").call(yAxisCall);

d3.csv("data/carsDataset.csv").then(function (data) {
  carData = data.map((d) => {
    return {
      model: d.Model,
      origin: d.Origin,
      year: +d.Year,
      cylinders: +d.Cylinders,
      horsepower: +d.Horsepower,
      mpg: +d.MPG,
      weight: +d.Weight.replace(/,/g, ""),
    };
  });
  update(carData);
});

$("#origin-select").on("change", () => {
  update(carData);
});

function update(data) {
  const t = d3.transition().duration(100);

  const origin = $("#origin-select").val();
  const allData = data;
  const filteredData = allData.filter((d) => {
    if (origin === "all") return true;
    else {
      return d.origin == origin;
    }
  });

  const circles = g.selectAll("circle").data(filteredData, (d) => d.model);

  circles.exit().remove();
  circles
    .enter()
    .append("circle")
    .attr("fill", (d) => OriginColor(d.origin))
    .attr("fill-opacity", 0.5)
    .on("mouseover", tip.show)
    .on("mouseout", tip.hide)
    .merge(circles)
    .transition(t)
    .attr("cy", (d) => y(d.mpg))
    .attr("cx", (d) => x(d.horsepower))
    .attr("r", (d) => Math.sqrt(area(d.weight) / Math.PI) / 4);
}
