import cs50
import csv

from flask import Flask, jsonify, redirect, render_template, request

# Configure application
app = Flask(__name__)

# Reload templates when they are changed
app.config["TEMPLATES_AUTO_RELOAD"] = True


@app.after_request
def after_request(response):
    """Disable caching"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/", methods=["GET"])
def get_index():
    return redirect("/form")


@app.route("/form", methods=["GET"])
def get_form():
    return render_template("form.html")


@app.route("/form", methods=["POST"])
def post_form():
    if not request.form.get("name") or not request.form.get("position") or not request.form.get("payment") or not request.form.get("card"):
        return render_template("error.html", message="Please fill all the fields or Bill will bury you in the hill")
    with open("survey.csv", "a") as file:
        writer = csv.DictWriter(file, fieldnames=["name", "position", "card", "payment"])
        writer.writerow({"name": request.form.get("name"), "position": request.form.get("position"), "card": request.form.get("card"), "payment": request.form.get("payment")})
    return redirect("/sheet")    

@app.route("/sheet", methods=["GET"])
def get_sheet():
    with open("survey.csv", "r") as file:
        reader = csv.reader(file)
        players = list(reader)
    return render_template("sheet.html", players=players)
