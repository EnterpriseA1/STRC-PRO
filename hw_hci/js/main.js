
const MARGIN = { LEFT: 100, RIGHT: 10, TOP: 10, BOTTOM: 100 }
const WIDTH = 900 - MARGIN.LEFT - MARGIN.RIGHT
const HEIGHT = 700 - MARGIN.TOP - MARGIN.BOTTOM

const svg = d3.select("#chart-area").append("svg")
  .attr("width", WIDTH + MARGIN.LEFT + MARGIN.RIGHT)
  .attr("height", HEIGHT + MARGIN.TOP + MARGIN.BOTTOM)

const g = svg.append("g")
  .attr("transform", `translate(${MARGIN.LEFT}, ${MARGIN.TOP})`)

let formattedData ;

const tip = d3.tip()
  .attr('class', 'd3-tip')
	.html(d => {
		let text = `<strong>Model:</strong> <span style='color:red;text-transform:capitalize'>${d.model}</span><br>`
		text += `<strong>Origin:</strong> <span style='color:red;text-transform:capitalize'>${d.origin}</span><br>`
        text += `<strong>Year:</strong> <span style='color:red;text-transform:capitalize'>${1900 + (+d.year)}</span><br>`
        text += `<strong>Cylinders:</strong> <span style='color:red;text-transform:capitalize'>${d.cylinders}</span><br>`
        text += `<strong>Horsepower:</strong> <span style='color:red;text-transform:capitalize'>${d.horsepower}</span><br>`
        text += `<strong>MPG:</strong> <span style='color:red;text-transform:capitalize'>${d.mpg}</span><br>`
        text += `<strong>Weight:</strong> <span style='color:red;text-transform:capitalize'>${d.weight}</span><br>`
		return text
	})
g.call(tip)
const x = d3.scaleLinear()
	.range([0,HEIGHT])
	.domain([40, 201])
const y = d3.scaleLinear()
	.range([HEIGHT, 0])
	.domain([12, 50])

const area = d3.scaleLinear()
    .domain([0, 4000])
    .range([25 * Math.PI, 1500 * Math.PI]);
const OriginColor = d3.scaleOrdinal(d3.schemePastel1)

// Labels
const xLabel = g.append("text")
	.attr("y", HEIGHT - 5)
	.attr("x", WIDTH - MARGIN.LEFT * 2 - MARGIN.RIGHT * 2 - 65)
	.attr("font-size", "15px")
	.attr("text-anchor", "right")
	.text("Horsepower")
const yLabel = g.append("text")
	
	.attr("y", 10)
	.attr("x", 10)    
	.attr("font-size", "15px")
    .attr("text-anchor", "left")
	.text("MPG")

const xAxisCall = d3.axisBottom(x)
.tickValues([60,80,100,120,140,160,180,200])

g.append("g")
	.attr("class", "x axis")
	.attr("transform", `translate(0, ${HEIGHT})`)
	.call(xAxisCall)

// Y Axis
const yAxisCall = d3.axisLeft(y)
.tickValues([15,20,25,30,35,40,45])

g.append("g")
	.attr("class", "y axis")
	.call(yAxisCall)

d3.csv("./carsDataset.csv").then(function(data) {
     formattedData =  data.map(d => {
        return {
            model: d.Model,
            origin: d.Origin,
            year: +d.Year,
            cylinders: +d.Cylinders,
            horsepower: +d.Horsepower,
            mpg: +d.MPG,
            weight: +d.Weight.replace(/,/g, "")
        };
    });
    update(formattedData);
});


$("#origin-select")
	.on("change", () => {
		update(formattedData)
	})


function update(data) {
    const t = d3.transition()
        .duration(100);

    const origin = $("#origin-select").val();
    const allData = data;
    const filteredData = allData.filter(d => {
        if (origin === "all") return true;
        else {
            return d.origin == origin;
        }
    });

    const circles = g.selectAll("circle")
        .data(filteredData, d => d.model);

    circles.exit().remove();
    circles.enter().append("circle")
        .attr("fill", d => OriginColor(d.origin))
        .attr("fill-opacity", 0.85)
        .on("mouseover", tip.show)
        .on("mouseout", tip.hide)
        .merge(circles)
        .transition(t)
        .attr("cy", d => y(d.mpg))
        .attr("cx", d => x(d.horsepower))
        .attr("r", d =>  Math.sqrt(area(d.weight) / Math.PI) / Math.PI)
}
