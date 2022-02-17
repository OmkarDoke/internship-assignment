import React, { Component } from 'react'

class ClassDemo extends Component {

  render() {
    return (
      <div>
          <h1>Hello class {this.props.firstParam} {this.props.secParam}</h1>
      </div>
    )
  }
}
export default ClassDemo
