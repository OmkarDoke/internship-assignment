import React, { Component } from 'react'

export class StatesDemo extends Component {

    // Shortcut rconst
    constructor()
    {
        super()
        this.state={
            message:"Inactive"
        }
    }
    changeState()
    {
        this.setState({
            "message":"Active"
        })
    }
  render() {
    return (
      <div>
          <h1>{this.state.message} <br/>click to active</h1>
          <button title="Click it" onClick={ ()=> this.changeState()}>Click me</button>
      </div>
    )
  }
}

export default StatesDemo