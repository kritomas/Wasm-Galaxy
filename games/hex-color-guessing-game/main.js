Module.onRuntimeInitialized = () =>
{
	const handleClick = Module.cwrap("chandleClick", "undefined", ["number", "number"]);

	const canvas = document.getElementById("ccanvas");
	canvas.addEventListener("click", (e) =>
	{
		handleClick(e.clientX, e.clientY);
	})
}
